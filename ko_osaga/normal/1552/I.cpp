/*
 * Rozwiazanie wzorcowe zadania mac/akjp001
 * Konstruujemy wzorzec, opisujacy poprawna permutacje kolumn,
 * po czym przy jego pomocy liczymy wynik
 * Zlozonosc czasowa: O((n + m)^2)
 * Author: Jakub Pachocki
 * Poprawki: Mateusz Baranowski
 */


#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 2000;
const int M = 2000;

int mod = 1000007;

void die(){
	printf("0\n");
	exit(0);
}

struct group{			// Podstawowa jednostka wzorca
	vector<int> domain;	// kolumny nalezace do grupy, ktore powinny ze soba sasiadowac
	vector<int> sets;	// numery wierszy, ktore naleza do grupy
};

/* dwukierunkowa lista grup tworzaca wzorzec                    *
 * grupy sasiadujace na liscie oznaczaja, ze odpowiadajace      *
 * grupy kolumn musza ze soba sasiadowac w poprawnej permutacji */
struct pattern{
	pattern *left, *right;
	group g;
};

bool matrix[N + 1][M + 1];	// Macierz wejsciowa
int Size[N + 1];			// ilosci jedynek w wierszach

bool intersects[N + 1];		// Czy wiersz przecina wzorzec?
					// Tablica globalna, gdyz po rozwazeniu wiersza
					// przecinajcego wzorzec zostanie usuniety ze zbioru wierszy

void insertBefore(pattern* p,group g){
	pattern* left = p->left;
	p->left = new pattern;
	p->left->right = p;
	p->left->left = left;
	p->left->g = g;
	if(p->left->left != NULL) p->left->left->right = p->left;
}

void insertAfter(pattern* p,group g){
	pattern* right = p->right;
	p->right = new pattern;
	p->right->left = p;
	p->right->right = right;
	p->right->g = g;
	if(p->right->right != NULL) p->right->right->left = p->right;
}

/* podziel grupe g uwzgledniajac istnienie zbioru set */
pair<group,group> split(group& g,int set){
	group gdifference, gintersection;
	for(vector<int>::iterator it = g.domain.begin(); it != g.domain.end(); ++it){
		if(matrix[set][*it]){
			gintersection.domain.push_back(*it);
			matrix[set][*it] = 0;
			--Size[set];
		}else gdifference.domain.push_back(*it);
	}
	if(gdifference.domain.empty()) return make_pair(gdifference, g);
	if(gintersection.domain.empty()) return make_pair(g, gintersection);
	bool swp = 0;
	if(gdifference.domain.size() < gintersection.domain.size()){
		swp = 1;
		swap(gdifference, gintersection);
	}
		/* Dzielimy wiersze, na takie, ktore przecinaja wiersz o numerze set, zawieraja sie w nim i pozostale
		 * Dzieki rozwazaniu mniejszej z grup mozliwa amortyzacja do O((n + m)^2)
		 */
	for(vector<int>::iterator it = g.sets.begin(); it != g.sets.end(); ++it){
		int intsize = 0;
		for(vector<int>::iterator jt = gintersection.domain.begin(); jt != gintersection.domain.end(); ++jt){
			if(matrix[*it][*jt]) ++intsize;
		}
		if(intsize == 0) gdifference.sets.push_back(*it);
		else if(intsize == Size[*it]) gintersection.sets.push_back(*it);
		else intersects[*it] = true;
	}
	if(swp) swap(gdifference, gintersection);
	return make_pair(gdifference, gintersection);
}

void erase(vector<int>& v,unsigned i){
	swap(v[i], v[v.size() - 1]);
	v.pop_back();
}

/* Funkcja f dla podanej grupy ilosc poprawnych permutacji */
int f(group g){
	vector<int> sets = g.sets;
	int result = 1;
	int iterations = 0;
	/* petla rozwaza kolejne spojne skladowe grafu, w ktorym kolumny sa wierzcholkami, *
	 * polaczonymi krawedzia jezeli istnieje wiersz, w ktorym obie maja jedynki        */
	while(g.domain.size() > 0){
		if(sets.empty()){
			iterations += g.domain.size();
			break;
		}
		++iterations;
		unsigned first = 0;
		/* rozpoczynamy od wierszu z najwieksza iloscia jedynek */
		for(unsigned i=1;i<sets.size();i++) if(Size[sets[i]] > Size[sets[first]]) first = i;
		int cur = sets[first];
		erase(sets,first);
		g.sets = sets;
		pair<group,group> sp = split(g, cur);
		pattern* p = new pattern;
		p->left = p->right = NULL;
		p->g = sp.second;
		g = sp.first;
		while(!sets.empty()){
			first = 0;
			/* znajdujemy zbior, ktory przecina nasz wzorzec */
			for(unsigned i=0;i<sets.size();i++){
				if(intersects[sets[i]]){
					first = i;
					break;
				}
			}
			if(!intersects[sets[first]]) break;
			cur = sets[first];
			erase(sets,first);
			bool gotLeft = 0, gotRight = 0;
			bool started = 0;
			sp = split(g, cur);
			group newElements = sp.second;
			g = sp.first;
			/* dodajemy zbior i uaktualniamy wzorzec */
			for(pattern* c = p; c != NULL; c = c->right){
				sp = split(c->g, cur);
				if(sp.second.domain.empty()){
					if(started){
						if(Size[cur]) die();
						break;
					}
				}else{
					if(started && Size[cur]){
						if(!sp.first.domain.empty()) die();
					}else if(started){
						if(!sp.first.domain.empty()){
							c->g = sp.first;
							insertBefore(c, sp.second);
						}else if(c->right == NULL){
							gotRight = 1;
						}
						break;
					}else if(Size[cur]){
						if(!sp.first.domain.empty()){
							c->g = sp.first;
							insertAfter(c, sp.second);
							c = c->right;
						}else if(c->left == NULL){
							gotLeft = 1;
						}
					}else{
						if(c->right == NULL){
							gotRight = 1;
							if(!sp.first.domain.empty()){
								c->g = sp.first;
								insertAfter(c, sp.second);
							}
						}else if(c->left == NULL){
							gotLeft = 1;
							if(!sp.first.domain.empty()){
								c->g = sp.first;
								insertBefore(c, sp.second);
								p = p->left;
							}
						}else die();
						break;
					}
					started = 1;
				}
			}
			if(!newElements.domain.empty()){
				if(gotRight){
					pattern* last = p;
					while(last->right != NULL) last = last->right;
					insertAfter(last,newElements);
				}else if(gotLeft){
					insertBefore(p,newElements);
					p = p->left;
				}else die();
			}
		}
		if(p->right != NULL){ // Sprawdzamy czy mozna odwrocic wzorzec
			result = (LL(result) * 2) % mod;
		}
		pattern* next;
		for(pattern* c = p; c != NULL; c = next){
			next = c->right;
			result = (LL(result) * f(c->g)) % mod;
			delete c;
		}
		sets = g.sets;
	}
	for(int i=1;i<=iterations;i++) result = (LL(result) * i) % mod;
	return result;
}

int n,m,z;

void read_data(){
	scanf("%d %d\n",&m ,&n);
	mod = 998244353;
	for(int i=1;i<=n;i++){
		int q; scanf("%d",&q);
		while(q--){
			scanf("%d", &z);
			matrix[i][z] = 1;
			Size[i]++;
		}
	}
}

int main(){
	read_data();
	group g;
	for(int i=1;i<=n;i++) if(Size[i]) g.sets.push_back(i);
	for(int i=1;i<=m;i++) g.domain.push_back(i);
	printf("%d\n",f(g));
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxn = 100500;
#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

struct node
{
	int x, y, c;
	ll s;
	node *l, *r;
	node (int X):x(X),y((rand()<<16)+rand()),c(1),s(X),l(NULL),r(NULL){};
};
void norm (node *&t)
{
	if (!t) return;
	t->s = t->x;
	t->c = 1;
	if (t->l) t->s += t->l->s, t->c += t->l->c;
	if (t->r) t->s += t->r->s, t->c += t->r->c;
};
void split (node *t, node *&l, node *&r, int x)
{
	if (!t) return (void)(l=r=NULL);
	if (x < t->x)
		split(t->l, l, t->l, x), r=t;
	else
		split(t->r, t->r, r, x), l=t;
	norm(t);
};
void merge (node *&t, node *l, node *r)
{
	if (!l || !r) return (void)(t=max(l,r));
	if (r->y > l->y)
		merge(r->l, l, r->l), t=r;
	else
		merge(l->r, l->r, r), t=l;
	norm(t);
};
void tr (node *t)
{
	if (!t) return;
	tr(t->l);
	cout << t->x << " ";
	tr(t->r);
};
bool fnd (node *t, int x)
{
	if (!t) return false;
	if (t->x == x) return true;
	if (t->x > x) return fnd(t->l, x);
	return fnd(t->r, x);
};
int kth (node *t, int x)
{
	if (t->x == x) return (t->l ? t->l->c : 0);
	if (t->x > x) return kth(t->l, x);
	return kth(t->r, x) + t->c - t->r->c;
};
void add (node *&t, int x)
{
	node *l, *r;
	split(t, l, r, x);
	merge(l, l, new node(x));
	merge(t,l,r);
};
void del (node *&t, int x)
{
	node *l, *m, *r;
	split(t, l, r, x);
	split(l,l,m,x-1);
	delete m;
	merge(t,l,r);
};
node *t[5], *l[5];
node *all=NULL;
void rotate (int x, int k)
{
	//cout << "Rotate " << x << " " << k << endl;
	//forn(j, 5) {tr(t[j]);cout<<"  |  ";}cout<<endl;
	forn(i, 5) split(t[i], t[i], l[i], x);
	forn(i, 5) merge(t[i], t[i], l[(i+k)%5]);
	//forn(j, 5) {tr(t[j]);cout<<"  |  ";}cout<<endl;
	//cout << endl;
};

void add (int x)
{
	add(all, x);
	//tr(all);cout<<endl;
	int k = kth(all, x);
	//cout << k << endl;
	rotate(x, 4);
	add(t[k%5], x);
};
void del (int x)
{
	int k = kth(all, x);
	del(all, x);
	del(t[k%5], x);
	rotate(x,1);
};
void sum ()
{
	cout << (t[2] ? t[2]->s : 0ll) << "\n";
};
int main()
{
	//freopen("input.txt","r", stdin);
	int x, n;
	char ty[10];
	cin >> n;
	forn(i, n)
	{
	//	forn(j, 5) {tr(t[j]);cout<<"  |  ";}cout<<endl;
		cin >> ty;
		if (ty[0] == 's')
			sum();
		else
		{
			cin >> x;
			if (ty[0] == 'a')
				add(x);
			else 
				del(x);
		}
	}	
};
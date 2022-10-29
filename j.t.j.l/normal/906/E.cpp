#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int ans[MAXN], pre[MAXN];

struct eertree {
  static const int SIZE = 1000000 + 10, SIGMA = 26;
  struct node {
    node *ch[SIGMA];
    node *link; // suffix link
    node *slink; // serial link: used in palindromic factorization
    int len; // the length of the node
    int occ; // the occurrences of this node in the whole string
    int num; // total number of suffix palindromes in this node
    int diff, dp, from; // used in palindromic factorization
    node() {
      memset(ch, 0, sizeof(ch));
      len = num = occ = 0;
      link = NULL;
      // used in palindromic factorization
      slink = NULL;
      diff = 0;
    }
  } pool[SIZE], *sz, *last;
  node *rto, *rte; // two initial root nodes
  int s[SIZE], n;
  eertree() {
    rto = new node(), rte = new node();
    rto->link = rte->link = rto;
    rto->len = -1, rte->len = 0;
    s[0] = -1; n = 0;
    last = rte;
    sz = pool;
  }
  node* get_link(node *u) {
    while (s[n - u->len - 1] != s[n]) u = u->link;
    return u;
  }
  bool add(int c) { // 
    s[++n] = c;
    last = get_link(last);
    bool flag = !last->ch[c];
    if (flag) {
      node *p = sz++;
      p->len = last->len + 2;
      if (p->len == 1) p->link = rte;
      else p->link = get_link(last->link)->ch[c];
      p->num = p->link->num + 1;
      last->ch[c] = p;
      // used for palindromic factorization
      p->diff = p->len - p->link->len;
      if (p->diff == p->link->diff) {
        p->slink = p->link->slink;
      } else p->slink = p->link;
    }
    last = last->ch[c];
    last->occ++;
    return flag;
  }
  // used for palindromic factorization
  // ansinf, ans[0] = 0
  void update(int ans[]) {
    for (node *p = last; p->len; p = p->slink) {
	  //if ((n - p->slink->len + p->diff) % 2 == 0){
		 // cout << n << ' ' << p->slink->len << ' ' << p->diff << ' ' << p->link->dp << ' ' << p->dp << ' ' << p->from << endl;
		if ((p->diff) % 2 == 1){
			if ((n - p->slink->len - p->diff) % 2 == 1 && p->link->diff == p->diff){
			  p->dp = ans[n - p->slink->len - p->diff - p->diff];
			  p->from = n - p->slink->len - p->diff - p->diff;
			  //cout << "!!!" << p->dp << endl;
			}
			else{
			  p->dp = ans[n - p->slink->len - p->diff];
			  p->from = n - p->slink->len - p->diff;
			}
		  if (p->diff == p->link->diff && p->link->link != NULL && p->link->diff == p->link->link->diff) {
			  if (p->link->link->dp < p->dp){
				p->dp = p->link->link->dp;
				p->from = p->link->link->from;
			  }
		  }
		}
		else{
		  p->dp = ans[n - p->slink->len - p->diff];
		  p->from = n - p->slink->len - p->diff;
		  if (p->diff == p->link->diff) {
			  if (p->link->dp < p->dp){
				p->dp = p->link->dp;
				p->from = p->link->from;
			  }
		  }
		}
	  if (p->dp + (n-p->from != 2) < ans[n]){
        ans[n] = p->dp + (n-p->from != 2);
		pre[n] = p->from;
	  }
    }
	//cout << ans[n] << endl;
  }
  ~eertree() {
    delete rto;
    delete rte;
  }
};

char s[MAXN], t[MAXN];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%s", s);
	scanf("%s", t);
	n = strlen(s);
	eertree* nico = new eertree();
	ans[0] = 0;
	for (int i = 1; i <= 2 * n + 2; i++)
		ans[i] = MM;
	for (int i = 0; i < n; i++){
		nico->add(s[i] - 'a');
		//nico->update(ans);
		//ans[i*2+1] = -MM;
		nico->add(t[i] - 'a');
		nico->update(ans);
	}
	
	if (ans[2 * n] > 1e8){
		puts("-1");
		return ;
	}
	int m = 2 * n;
	vector<PII> maki;
	int ccnt = 0;
	while(m != 0){
		if (m-pre[m]!=2)
			maki.push_back(PII(pre[m]/2+1, m/2));
		m = pre[m];
	}
	printf("%d\n", maki.size());
	reverse(maki.begin(), maki.end());
	for (auto &x : maki)
		printf("%d %d\n", x.first, x.second);
}

void printans(){

}

int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}
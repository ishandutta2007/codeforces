#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <tuple>
#include <complex>


#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define forn() for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
#define fill(x) memset((x), 0, sizeof((x)))

using namespace std;

const int inf = 2e9;
const double eps = 1e-6;
const int maxn = 5e5 + 5, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18;

void bad(string mes = "Impossible"){cout << mes;exit(0);}

template<typename T>
string bin(T x){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % 2);
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}


template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
    while (c == ' ' || c == '\n')
        c = getchar();
    if (c == '-')
        m = -1, c = getchar();
    while (c != ' ' && c != '\n')
        ans = ans * 10 + c - '0', c = getchar();
    return ans * m;
}

template<typename T>
T binpow(T n, T s)
{
    if (s == 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2) % base;
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

template<typename T>
T sqr(T x)
{
    return x * x;
}

int brot[maxn];


struct node
{
    node * left;
    node * right;
    int mx, mn;
    int key;
    int pr;
   // node(){count=1;mn=inf;}
    node(int key):left(0),right(0),key(key),mx(key), mn(key){
        pr = (rand()<<15) + rand();
    }
};

typedef node * pnode;


int get_min(pnode T)
{
    if (!T)
        return inf;
    return T->mn;
}

int get_max(pnode T)
{
    if (!T)
        return 0;
    return T->mx;
}


void update(pnode T)
{
    if (!T)
        return;
    T->mx = max(T->key, max(get_max(T->left), get_max(T->right)));
    T->mn = min(T->key, min(get_min(T->left), get_min(T->right)));   
}

void print(pnode root) {
    if (root != NULL) {
        print(root->left);
        printf("%d ", root->key);
        print(root->right);
    }
}

void split(pnode root,pnode &L,pnode &R,int pos)
{
    if (root == NULL){
        L = R = NULL;
        return;
    }

    int key = root->key;
    if (pos <= key)
    {
        split(root->left,L,root->left,pos);
        R = root;
    } else
    {
        split(root->right,root->right,R,pos);
        L = root;
    }

    update(root);
}

pnode merge(pnode L,pnode R)
{

    if (L == NULL){
        return R;
    }
    if (R == NULL){
        return L;
    }
    pnode ans = NULL;
    if (R->pr > L->pr)
    {
        R->left = merge(L,R->left);
        ans = R;
    } else
    {
        L->right = merge(L->right,R);
        ans = L;
    }

    update(ans);
    return ans;
}

/*

pnode add(pnode root,  int value, int pos,bool debug = 0) {
    pnode left, right;
    split(root, left, right, pos);
    pnode singleton = new node(value);
    return merge(left, merge(singleton, right));
}

pnode remove(pnode root, int leftPos, int rightPos) {
    pnode left, middle, right;
    split(root, middle, right, rightPos);
    split(middle, left, middle, leftPos);
    return merge(left, right);
}

pnode cut(pnode root,pnode &L,pnode &R,int ql,int qr)
{
    pnode M=NULL;
    split(root,M,R,qr);
    split(M,L,M,ql);
    return M;
}
*/
void debug(pnode a,pnode b,pnode c)
{
    print(a);
    cout<<endl;
    print(b);
    cout<<endl;
    print(c);
    cout<<endl;
}

bool exist(pnode T,int key)
{
    if (!T)
        return 0;
    if (T->key == key)
        return 1;
    if (T->key < key)
        return exist(T->right,key);
    else
        return exist(T->left,key);
}
pnode add(pnode root,int key)
{
    if (exist(root,key))
        return root;
    pnode single = new node(key);
    pnode L,R;
    split(root,L,R,key);
    return merge(L,merge(single,R));
}

vector<int> tmp;

void hark(pnode T)
{
    if (T){
        hark(T->left);
        tmp.pb(T->key);
        hark(T->right);
    }
}

int main()
{
    int n, m, p;
    scanf("%d %d %d\n", &n, &m, &p);
    p--;

    string s, old;
    cin >> s;
    old = s;
    vector<int> in;
    in.pb(0);

    for (int i = 1; i < s.size(); i++){
        if (s[i] == '(')
            in.pb(i);
        else
        {
            int b = in.back();
            brot[i] = b;
            brot[b] = i;
            in.pop_back();
        }
    }

    pnode T = 0;

    for (int i = 0; i < n; i++)
        T = add(T, i);

    cin >> s;
    for (int i = 0; i < s.size(); i++){
        char cur = s[i];
        if (cur == 'L'){
            pnode L, R;
            split(T, L, R, p); // p - 1
            if (L == 0)
                return 1;
            p = L->mx;
            T = merge(L, R);
        }
        if (cur == 'R'){
            pnode L, R;
            split(T, L, R, p + 1);
            if (R == 0)
                return 2;
            p = R->mn;
            T = merge(L, R);
        }
        if (cur == 'D'){
            int l = brot[p], r = p;
            if (l > r)
                swap(l, r);
            pnode L, M, R;
            split(T, M, R, r + 1); // r - 1
            split(M, L, M, l); // l +- 1
            if (R == 0){
                if (L == 0)
                    return 3;
                p = L->mx;
            }
            else
                p = R->mn;
            T = merge(L, R);
        }
        // print(T);
        // cout << ':' << p << endl;
    }

    hark(T);
    for (int i = 0; i < tmp.size(); i++)
        printf("%c", old[tmp[i]]);
    puts("");
    return 0;
}
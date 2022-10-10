///////////////////////////////
// Template By: Agus Sentosa //
//       17 - 5 - 2014       //
///////////////////////////////
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <cstring>
#include <cmath>
#include <functional>
#include <utility>

//I/O
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <istream>
#include <ostream>

//Data Type
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <bitset>

//Data Type
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define LL long long
#define ULL unsigned long long

//Data Type Properties
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define popb pop_back

//Macro
#define sqr(x) ((x) * (x))
#define all(v) (v).begin(),(v).end()
#define sortv(v) sort(all(v))
#define num(x) ((x)-'0')
#define ch(x) ((x)+'0')
#define bit_count __builtin_popcount
#define bit_countll __builtin_popcountll
#define THIS (*this)

//Output
#define endl '\n'

//Compiling & Debugging
#ifdef DEBUG
#define DO_IF_DEBUG_FLAG_IS_ON 1
#else
#define DO_IF_DEBUG_FLAG_IS_ON 0
#endif
#define DoDebug if(DO_IF_DEBUG_FLAG_IS_ON)

//???????????????????
#define Fokus using
#define Tahun_Terakhir namespace std;

Fokus Tahun_Terakhir;

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
#define g getchar_unlocked
template<class T>
bool io(T &res){
    static char c=' ';
    while(c == ' ' || c == '\n')c = g();
    if(c == -1)return 0;
    res = num(c);
    while((c=g()) && c != ' ' && c != '\n' && c!=-1){ res = (res << 3) + (res << 1) + num(c); }
    return 1;
}

template<class T>
string inttostr(T x){
    string res="";
    while(x){
        char t=ch(x%10); x/=10; res=t+res;
    }
    return res;
}

template<class T>
T strtoint(string x){
    T res=0;
    for(int i=0;i<x.size();i++){
        res=(res<<3)+(res<<1)+num(x[i]);
    }
    return res;
}
void open(string a){
    freopen((a+".in").c_str(),"r",stdin);
    freopen((a+".out").c_str(),"w",stdout);
}
void close(){
    fclose(stdin);
    fclose(stdout);
}

//Constant
#define INF 1000000007
#define LINF 1000000000000000007ll
#define DINF 1000000000000000007.00
#define INV (-INF)
#define LINV (-LINF)
#define DINV (-DINF)
#define EPS 1e-9
#define MOD 1000000007
///////////////////////////////
//      End of Template      //
///////////////////////////////

int arr[100005];
int vis[100005];

void no(int n){
  cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    
    int n; cin >> n;
    int a = -1 , b = -1;
    for(int i = 1 ; i <= n ; i ++){
        cin >> arr[i];
    }
    
    for(int i = 1 ; i <= n ; i ++){
        if(i == arr[i]){
            cout << "YES" << endl;
            for(int j = 1 ; j <= n ; j ++){
                if(i == j)continue;
                cout << i << ' ' << j << endl;
            }
            
            return 0;
        }
    }
    
    for(int i = 1 ; i <= n ; i ++){
        if(i == arr[arr[i]])
            a = i , b = arr[i];
    }
    
    
    if(a != -1){
        memset(vis,0,sizeof vis);
        
        vector<pii> V;
        
        vis[a] = 1;
        vis[b] = 1;
        
        V.pb({a,b});
        
        for(int i = 1 ; i <= n ; i ++){
            if(!vis[i]){
                int cntr = 0;
                int len = 0;
                for(int j = i ; cntr <= 1 ; j = arr[j]){
                    if(j == i)cntr++;
                    len++;
                }
                len--;
            
                if(len & 1){
                    no(n);
                    return 0;
                }
                
                for(int j = i ; !vis[j] ; j = arr[j]){
                    vis[j] = 1;
                    V.pb({j,a});
                    swap(a,b);
                }
            }
        }
        cout << "YES" << endl;
        for(pii i : V){
            cout << i.f << ' ' << i.s << endl;
        }
        return 0;
        
    }
    
    no(n);

    return 0;
}
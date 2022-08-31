/*/ Author: kal013 /*/
//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
#define ll long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef priority_queue<ppi> max_heap_ppi;
#define For(i,n) for(int i=0;i<(int)n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,n) for(int i=1;i<=n;++i)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...)
#endif
const int maxn=1e6+100;
const int MaxN=3e5+100;
// const int mod=1e9+7;
#ifdef int
const int INF=1e16;
#else
const int INF=1e9;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set
#endif

// inline int fast_expo(int base,int power,int modulo=mod){
//     base%=modulo;
//     if (base<0) base+=modulo;
//     ll x=base,cnt=power,ans=1;
//     while(cnt){
//         if (cnt&1) ans=(ans*x)%modulo;
//         x=(x*x)%modulo;
//         cnt>>=1;
//     }
//     // int tmp=ans;
//     return ans;
// }
// inline int inv(int base,int modulo=mod){
//     return fast_expo(base,modulo-2,modulo);
// }


/*/-----------------------------Code begins----------------------------------/*/
const int mod1=1e9+7;
const int mod2=1e9+9;

const int pri[2]={11,17};
const int mod[2]={mod1,mod2};



int hsha[2][2][MaxN],hashb[2][2][MaxN];

int val[2][2][MaxN];

void pre(){
	For(i,2){
		For(j,2){
			val[i][j][0]=1;

			for(int z=1;z<MaxN;++z){
				val[i][j][z]=(val[i][j][z-1]*pri[i])%mod[j];
			}
		}
	}
}

const int Maxn=3e5+100;
int Sa[MaxN],Sb[MaxN],Ea[MaxN],Eb[Maxn];

int ophs[2][2],clhs[2][2];

vi opa[MaxN],opb[MaxN],cla[MaxN],clb[MaxN];



void solve(){
	int n;
	cin>>n;

	// vector<pair<int,pii> > Va,Vb;


	set<int> posA,posB;
	map<int,int> idxA,idxB;
	Rep(i,n){
		cin>>Sa[i]>>Ea[i]>>Sb[i]>>Eb[i];
		posA.insert(Sa[i]);
		posA.insert(Ea[i]);
		posB.insert(Sb[i]);
		posB.insert(Eb[i]);
		// Va.pb({Sa[i],{1,i}});
		// Va.pb({Ea[i]+1,{0,i}});
		// Vb.pb({Sb[i],{1,i}});
		// Vb.pb({Eb[i]+1,{0,i}});
	}
	int us=0;
	for(auto a:posA){
		idxA[a]=us++;
	}
	assert(us==posA.size());
	us=0;
	for(auto b:posB){
		idxB[b]=us++;
	}
	assert(us==posB.size());
	us=0;

	Rep(i,n){
		opa[idxA[Sa[i]]].pb(i);



		opb[idxB[Sb[i]]].pb(i);
		cla[idxA[Ea[i]]].pb(i);
		clb[idxB[Eb[i]]].pb(i);

	}

	// trace(idxA,idxB,posA,posB);


	for(int z=0;z<posA.size();++z){
		
		for(auto i:opa[z]){
			For(j,2){
				For(k,2){
					hsha[j][k][i]=(-clhs[j][k]+mod[k])%mod[k];
					ophs[j][k]=(ophs[j][k]+val[j][k][i])%mod[k];
					// chs[j][k]=(chs[j][k]-val[j][k][i]+mod[k])%mod[k];
				}
			}
		}

		for(auto i:cla[z]){
			For(j,2){
				For(k,2){
					hsha[j][k][i]=(ophs[j][k]+hsha[j][k][i])%mod[k];
					clhs[j][k]=(clhs[j][k]+val[j][k][i])%mod[k];
					// chs[j][k]=(chs[j][k]-val[j][k][i]+mod[k])%mod[k];
				}
			}
		}
	}
	For(j,2) For(k,2) {ophs[j][k]=0;clhs[j][k]=0;}

	for(int z=0;z<posB.size();++z){
		
		for(auto i:opb[z]){
			For(j,2){
				For(k,2){
					hashb[j][k][i]=(-clhs[j][k]+mod[k])%mod[k];
					ophs[j][k]=(ophs[j][k]+val[j][k][i])%mod[k];
					// chs[j][k]=(chs[j][k]-val[j][k][i]+mod[k])%mod[k];
				}
			}
		}

		for(auto i:clb[z]){
			For(j,2){
				For(k,2){
					hashb[j][k][i]=(ophs[j][k]+hashb[j][k][i])%mod[k];
					clhs[j][k]=(clhs[j][k]+val[j][k][i])%mod[k];
					// chs[j][k]=(chs[j][k]-val[j][k][i]+mod[k])%mod[k];
				}
			}
		}
	}

	// for(auto v:Va){
	// 	int i=v.S.S;
	// 	if (v.S.F==0){
	// 		For(j,2){
	// 			For(k,2){
	// 				hsha[j][k][i]=(chs[j][k]-hsha[j][k][i]+mod[k])%mod[k];
	// 				// chs[j][k]=(chs[j][k]-val[j][k][i]+mod[k])%mod[k];
	// 			}
	// 		}
	// 	}
	// 	else{
	// 		For(j,2){
	// 			For(k,2){
	// 				hsha[j][k][i]=chs[j][k];
	// 				chs[j][k]=(chs[j][k]+val[j][k][i])%mod[k];
	// 			}
	// 		}
	// 	}
	// }
	
	// for(auto v:Vb){
	// 	int i=v.S.S;
	// 	if (v.S.F==0){
	// 		For(j,2){
	// 			For(k,2){
	// 				hashb[j][k][i]=(chs[j][k]-hashb[j][k][i]+mod[k])%mod[k];
	// 				// chs[j][k]=(chs[j][k]-val[j][k][i]+mod[k])%mod[k];
	// 			}
	// 		}
	// 	}
	// 	else{
	// 		For(j,2){
	// 			For(k,2){
	// 				hashb[j][k][i]=chs[j][k];
	// 				chs[j][k]=(chs[j][k]+val[j][k][i])%mod[k];
	// 			}
	// 		}
	// 	}
	// }
	bool pos=1;

	Rep(i,n){
		if (!pos) break;
		For(j,2) For(k,2){
			if (hsha[j][k][i]!=hashb[j][k][i]) {pos=0;break;}
		}
	}
	if (pos){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
   	pre();
    fio;
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}
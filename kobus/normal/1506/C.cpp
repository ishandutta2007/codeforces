#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAXN 112345
#define MOD 1000000007
#define f first
#define s second
#define pii pair<long long, long long>
#define INF LLONG_MAX
#define int long long

string a,b;

bool testa(int ai,int aj,int bi,int bj){
    for(int i=0;i<aj-ai+1;i++){
        if(a[ai+i]!=b[bi+i])return 0;
    }
    return 1;
}
 
int32_t main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int tam=0;
        for(int ai=0;ai<a.size();ai++){
            for(int aj=ai;aj<a.size();aj++){
                for(int bi=0;bi<b.size();bi++){
                    for(int bj=bi;bj<b.size();bj++){
                        if(aj-ai!=bj-bi)continue;
                        if(testa(ai,aj,bi,aj)){
                            tam=max(tam,aj-ai+1);
                        }
                    }
                }
            }
        }
        //cout<<tam<<endl;
        cout<<a.size()+b.size()-2*tam<<endl;
    }

    return 0;
}
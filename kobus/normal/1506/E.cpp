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

int v[212345];
int p[212345];
 
int32_t main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int> falta;
        for(int i=0;i<n;i++){
            cin>>v[i];
            falta.insert(i+1);
        }
        for(int i=0;i<n;i++){
            if(i==0 || v[i]!=v[i-1]){
                p[i]=v[i];
                falta.erase(v[i]);
            }
            else{
                p[i]=*falta.begin();
                falta.erase(falta.begin());
            }
        }
        for(int i=0;i<n;i++)cout<<p[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++){
            falta.insert(-1*(i+1));
        }
        for(int i=0;i<n;i++){

            p[i]=(-1)*(*falta.lower_bound(-1*v[i]));
            falta.erase(*falta.lower_bound(-1*v[i]));
        }
        for(int i=0;i<n;i++)cout<<p[i]<<" ";
        cout<<endl;


    }

    return 0;
}
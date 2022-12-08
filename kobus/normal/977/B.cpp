#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define MAXN 112
#define INF LLONG_MAX
#define double long double
#define int long long
#define pii pair<long long,long long>
#define f first
#define s second
#define mp make_pair
#define eps 1e-11
#define pi acos(-1)
#define MOD 1000000007

map<string,int> freq;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(9);
    cout.setf(ios::fixed);

    int n;
    cin>>n;
    string s;
    cin>>s;
    int maxi=-1;
    string best;
    for(int i=0;i<n-1;i++){
    	string par={s[i],s[i+1]};
    	freq[par]++;
    	if(freq[par]>maxi){
    		maxi=freq[par];
    		best=par;
    	}
    }
    cout<<best<<endl;
    
   
    return 0;
 
}
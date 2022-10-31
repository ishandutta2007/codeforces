// Hydro submission #616e40c9e73a88bc078f9a65@1634615497483
#include<iostream>
#include<map>
using namespace std;
const int N=1e7+9;
int primes[N], cnt;    
bool st[N];       
 
void get_primes(int n)
{
	n=N;
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
int bym(int n){
	int res=1;
	for(int i=0;primes[i]<=n/primes[i];i++){
		int u=0;
		while(n%primes[i]==0){
			n/=primes[i];
			u++;
		}
		if(u%2)res*=primes[i];
	}
	if(n!=1)res*=n;
	return res;
}
int main(){
	int T; 
	cin>>T;
	get_primes(N);
	while(T--){
		map<int,int>mp;
		int n,k;
		cin>>n>>k;
		int ans=1;
		for(int i=1;i<=n;i++){
			int s;
			scanf("%d",&s);
			int t;
				t=bym(s);
			if(mp[t]){
				mp.clear();
				ans++;
			//	mp[t]++;
			}
			mp[t]++;
		}
		cout<<ans<<endl; 
		//mp.clear();
	}
}
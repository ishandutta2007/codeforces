#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MOD 1000000007

int main()
{
	int n,d;
	cin >> n >> d;
	int ans=0,cur=0;
	bool b;
	char c;
	for(int i=0;i<d;i++){
		b = false;
		for(int j=0;j<n;j++){
			c='\n';
			while(c=='\n'){
				cin >> c;
			}
			if(c=='0'){
				b = true;
			}
		}
		if(b){
			cur++;
			ans = max(ans,cur);
		}else{
			cur = 0;
		}
	}
	cout << ans;
}
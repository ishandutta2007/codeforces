#include<bits/stdc++.h>
using namespace std;
int n;

int main()
{
	cin >> n;
	if(n%2){
		cout << "YES" << endl;
		for(int i=1;i<=n;i++){
			if(i&1)printf("%d ",i*2);
			else printf("%d ",i*2-1);
		}
		for(int i=1;i<=n;i++){
			if(!(i&1))printf("%d ",i*2);
			else printf("%d ",i*2-1);
		}
	}else cout << "NO" << endl;
}
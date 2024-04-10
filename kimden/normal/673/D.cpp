#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	int a,b,c,d;
	cin >> n >> k;
	cin >> a >> b >> c >> d;
	if(n==4){
		cout << -1;
		return 0;
	}
	if(k<=n){
		// ?
		cout << -1;
		return 0;
	}
	if(n==5){
		int e = 15-a-b-c-d;
		printf("%d %d %d %d %d\n",a,c,e,d,b);
		printf("%d %d %d %d %d",c,a,e,b,d);
		return 0;
	}
	int u=1,x,y;
	while((((u==a)||(u==b))||((u==c)||(u==d)))&&(u<=n)){
		u++;
	}
	x = u;
	u++;
	while((((u==a)||(u==b))||((u==c)||(u==d)))&&(u<=n)){
		u++;
	}
	y = u;
	u++;
	vector<int> v;
	while(1){
		while(((u==a)||(u==b))||((u==c)||(u==d))){
			u++;
		}
		if(u>n)
			break;
		v.push_back(u);
		u++;
	}
	cout << a << " ";
	for(auto it = v.begin();it!=v.end();it++){
		cout << *it << " ";
	}
	printf("%d %d %d %d %d\n",d,y,x,c,b);
	printf("%d %d %d %d %d ",c,b,y,x,a);
	for(auto it = v.begin();it!=v.end();it++){
		cout << *it << " ";
	}
	cout << d;
	return 0;
}
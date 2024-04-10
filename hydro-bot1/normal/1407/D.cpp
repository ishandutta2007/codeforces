// Hydro submission #6309cbdd45cdc66f60cc2681@1661586398129
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,h[N],f[N];
stack<int> s1,s2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
		f[i]=INT_MAX;
	}
	f[1]=0,s1.push(1),s2.push(1);
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+1;
		while(s1.size()&&h[i]>=h[s1.top()]){
			int x=s1.top();
			s1.pop();
			if(h[x]!=h[i]&&s1.size())
				f[i]=min(f[i],f[s1.top()]+1);
		}
		while(s2.size()&&h[i]<=h[s2.top()]){
			int x=s2.top();
			s2.pop();
			if(h[x]!=h[i]&&s2.size())
				f[i]=min(f[i],f[s2.top()]+1);
		}
		s1.push(i),s2.push(i);
	}
	printf("%d",f[n]);
	return 0;//
}
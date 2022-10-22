#include<bits/stdc++.h>
using namespace std;
int n; double a[110000],b[110000],c[110000],d[110000];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	double sa=0,sb=0;
	for (int i=1;i<=n;i++){
		sa+=a[i]; sb+=b[i];
		double B=sa+sb,C=sa;
		c[i]=((B-sqrt(max(.0,B*B-4*C)))/2);
		d[i]=((B+sqrt(max(.0,B*B-4*C)))/2);
	}
	for (int i=1;i<=n;i++) printf("%.8lf ",c[i]-c[i-1]); putchar('\n');
	for (int i=1;i<=n;i++) printf("%.8lf ",d[i]-d[i-1]); putchar('\n');
	return 0;
}
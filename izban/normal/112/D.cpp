#include <iostream>
#include <string>
#include <map>
#include <math.h>
using namespace std;
int a[100001],b[100001],x,y,ans;
void check(int c, int i)
{
	if (y==0) ans+=1;
	else if (b[c]<i-y) ans+=1;
}
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n; int i; int j;
	for (i=0; i<100001; i++) b[i]=-1;
	cin >> n;
	for (i=0; i<n; i++) {
		cin >> x >> y;
		a[i]=x;
		ans=0;
		for (j=1; j<=sqrt(x*1.0); j++) {
			if (!(x%j)) {
				check(j, i); 
				if (j!=x/j) check(x/j, i);
				b[j]=i; b[x/j]=i;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
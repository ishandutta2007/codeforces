/*********************************************************************
 * Sourceysy
 * ProblemCF768E
 * Authorhydd
 * Date2020/9/3
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int x,res=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		for (int j=1;;j++){
			x-=j;
			if (x<=j){ res^=j; break;}
		}
	}
	if (res) puts("NO");
	else puts("YES");
	return 0;
}
//Problem B
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n;
long long sx,sy;
int main(){
    scanf("%d",&n);
	for(int i=0;i<n<<1;i++){
		int a,b;scanf("%d%d",&a,&b);
		sx+=a,sy+=b;
	}
	cout<<sx/n<<" "<<sy/n;
    return 0;
}
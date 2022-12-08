#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,a,b,c,d;

int main()
{
	cin >> t ;
	while(t--){
		cin >> a >> b >> c >> d;
		int tarx=b-a,tary=d-c;
		int x,y,x1,y1,x2,y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		x1-=x,x2-=x,y1-=y,y2-=y;
		int flg=1;
		if(tarx<=x2&&tarx>=x1&&tary<=y2&&tary>=y1){
			if(x1==0&&x2==0){
				if(a||b)flg=0;
			}
			if(y1==0&&y2==0){
				if(c||d)flg=0;
			}
		}else flg=0;
		cout << (flg?"Yes":"No") << endl;
	}
}
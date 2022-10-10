#include <bits/stdc++.h>
#define ll long long
using namespace std;
int i,j,k,n,m;
void read(int &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
void read(ll &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
struct paper{
	int x1,y1,x2,y2;
}a,b,c;
void ok(){
	cout<<"NO"<<endl;
	exit(0);
}
int main() {
	read(a.x1);read(a.y1);read(a.x2);read(a.y2);
	read(b.x1);read(b.y1);read(b.x2);read(b.y2);
	read(c.x1);read(c.y1);read(c.x2);read(c.y2);
	swap(a,c);
	if(a.x1<=c.x1 && a.x2>=c.x2 && a.y1<=c.y1 && a.y2>=c.y2)ok();
	if(b.x1<=c.x1 && b.x2>=c.x2 && b.y1<=c.y1 && b.y2>=c.y2)ok();
	if((a.x1<=c.x1 && a.x2>=c.x2 && a.y1<=c.y1) &&
	   (b.x1<=c.x1 && b.x2>=c.x2 && b.y2>=c.y2) &&
	   (b.y1<=a.y2))ok();
	if((a.x1<=c.x1 && a.x2>=c.x2 && a.y2>=c.y2) &&
	   (b.x1<=c.x1 && b.x2>=c.x2 && b.y1<=c.y1) &&
	   (b.y2>=a.y1))ok();
	if((a.y1<=c.y1 && a.y2>=c.y2 && a.x2>=c.x2) &&
	   (b.y1<=c.y1 && b.y2>=c.y2 && b.x1<=c.x1) &&
	   (b.x2>=a.x1))ok();
	if((b.y1<=c.y1 && b.y2>=c.y2 && b.x2>=c.x2) &&
	   (a.y1<=c.y1 && a.y2>=c.y2 && a.x1<=c.x1) &&
	   (a.x2>=b.x1))ok();
	cout<<"YES"<<endl;
    //cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
    return 0;
}
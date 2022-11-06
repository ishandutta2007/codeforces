#include<bits/stdc++.h>
using namespace std;
long long up=999999999;
long long x,y;
long long tx,ty,A,B,C,D;
void write(long long x,long long y){
	cout<<"? "<<x+1<<' '<<y+1<<endl;
}
long long xx,yy,xxx,yyy;
int main(){
	write(0,0);cin>>A;
	write(0,up);cin>>B;
	write(up,0);cin>>C;
	write(up,up);cin>>D;
	tx=(A+up-C)/2;write(tx,0);cin>>yy;
	tx=(B+up-D)/2;write(tx,up);cin>>yyy;
    ty=(A-B+up)/2;write(0,ty);cin>>xx;
	ty=(C-D+up)/2;write(up,ty);cin>>xxx;
	cout<<"! "<<xx+1<<' '<<yy+1<<' '<<up+1-xxx<<' '<<up+1-yyy<<endl;
}
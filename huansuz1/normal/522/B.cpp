#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<map>

using namespace std;
int x[234567],y[234567],n,s,m,z,m2;

int main(){
cin>>n;
for (int i=0; i<n; i++) {
	cin>>x[i]>>y[i];
	s+=x[i];
	if (m<y[i]) {m=y[i];z=1;} else
		if (m==y[i]) z++;
}
for (int i=0; i<n; i++) {
	if (y[i]<m && m2<y[i]) m2=y[i];
}

for (int i=0; i<n; i++){
	if (y[i]==m && z==1) cout<<(s-x[i])*m2<<" "; else cout<<(s-x[i])*m<<" ";

}


}
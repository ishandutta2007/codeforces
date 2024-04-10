// Hydro submission #62ec9c7a4d95d40f2e19b6df@1659673723105
#include<bits/stdc++.h>
using namespace std;   
double x[3],y[3],r[3];   
double calc(double x1,double y1){
	double ret=0;  
	double t[3];  
	for(int i=0;i<3;i++)  
		t[i]=sqrt((x1-x[i])*(x1-x[i])+(y1-y[i])*(y1-y[i]))/r[i];  
	ret=(t[0]-t[1])*(t[0]-t[1])+(t[1]-t[2])*(t[1]-t[2])+(t[2]-t[0])*(t[2]-t[0]) ;  
	return ret;  
} 
int main(){  
	for(int i=0;i<3;i++)  
		cin>>x[i]>>y[i]>>r[i]; 
	double tx=0,ty=0;  
	for(int i=0;i<3;i++)  
		tx+=x[i]/3,ty+=y[i]/3;  
	double s=1; 
	while (s>1e-6){ 
		if(calc(tx,ty)>calc(tx+s,ty)) 
			tx+=s;  
		else if(calc(tx,ty)>calc(tx-s,ty)) 
			tx-=s;  
		else if(calc(tx,ty)>calc(tx,ty+s))  
			ty+=s;  
		else if(calc(tx,ty)>calc(tx,ty-s)) 
			ty-=s;  
		else s*=0.7;   
	}   
	if(calc(tx,ty)<1e-5)   
		cout<<fixed<<setprecision(5)<<tx<<" "<<ty<<endl;  
	return 0; 
}
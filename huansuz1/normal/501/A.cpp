 #include <conio.h> 
 #include <iostream> 
 #include <math.h> 
 using namespace std;
 int n,m,a,b;
	
 int main()   {
 cin>>n>>m>>a>>b;
 double x=max((n*3)/10,n-(n/250)*a);   
 double x1=max((m*3)/10,m-(m/250)*b);
 if (x>x1) cout<<"Misha"; else
 if (x<x1) cout<<"Vasya"; else cout<<"Tie";
	
	return 0;
 }
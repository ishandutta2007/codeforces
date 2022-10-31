#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
                 
#define y1 tupoi_cmath
#define sz 20
using namespace std;
 
int n, m, z, z1;
int a, b, x[1234], y[1234], x1[1234], y1[1234];

 
int main(){
	scanf("%d %d", &a, &b);
	
	int c =  ((a * a) + (b * b));

	for (int i = -1000; i <= 1000; i++)
		for (int j = -1000; j <= 1000; j++){
			if ((i != 0 && j != 0) && a * a == ((i - 0) * (i - 0)) + ((j - 0) * (j - 0))) 
				{ x[z] = i; y[z++] = j;}
			if ((i != 0 && j != 0) && b * b == ((i - 0) * (i - 0)) + ((j - 0) * (j - 0)))
				{ x1[z1] = i; y1[z1++] = j;}
		 }



	
		for (int i = 0; i < z; i++)
			for (int j = 0; j < z1; j++)
				if (c  == (x[i] - x1[j]) * (x[i] - x1[j]) + (y[i] - y1[j]) * (y[i] - y1[j]) && (x[i] != x1[j] && y[i] != y1[j]))
					{cout<<"YES"<<endl<<0<<" "<<0<<endl; 
					 cout<<x[i]<<" "<<y[i]<<endl;
					 cout<<x1[j]<<" "<<y1[j]<<endl;
					 exit(0);}  
	cout<<"NO";
    return 0;
}
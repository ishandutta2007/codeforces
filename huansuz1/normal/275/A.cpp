#include<iostream>
#include<algorithm>

using namespace std;

int x,y,n,p,t ,z, a[123][123],b[123][123];

int main(){
	for (int i=1; i<=3; i++)
		for (int j=1; j<=3; j++) {
			cin>>b[i][j];
		a[i][j]=1;	                      
	}
	for (int i=1; i<=3; i++)
		for (int j=1; j<=3; j++)
			if (b[i][j]>0){
			for (int o=1; o<=b[i][j];o++)
			  	{
			  	if (a[i][j]==0) a[i][j]=1; else a[i][j]=0;
			  	if (a[i][j-1]==0) a[i][j-1]=1; else a[i][j-1]=0;
			  	if (a[i-1][j]==0) a[i-1][j]=1; else a[i-1][j]=0;
			  //	if (a[i-1][j-1]==0) a[i][j]=1; else a[i][j]=0;
			  	if (a[i][j+1]==0) a[i][j+1]=1; else a[i][j+1]=0;
			  	if (a[i+1][j]==0) a[i+1][j]=1; else a[i+1][j]=0;
			  //	if (a[i+1][j+1]==0) a[i][j]=1; else a[i][j]=0;
			  //	if (a[i-1][j+1]==0) a[i][j]=1; else a[i][j]=0;
			  //	if (a[i+1][j-1]==0) a[i][j]=1; else a[i][j]=0;
				    }
					}       
	for (int i=1; i<=3; i++)
		{
		for (int j=1; j<=3; j++)
			cout<<a[i][j];
		cout<<endl;
		}			
 	return 0;          
}
// Hydro submission #6332f9238e8a37024c4a1b3d@1664284964170
#include<iostream>
#include<algorithm>
using namespace std;
int n,k;//
int main(){
	cin>>n>>k;
	const int qwq=n+5;
	int a[qwq];//
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	if(k==1){//
    sort(a+1,a+n+1);//
    cout<<a[1]<<endl;//
    }
	else if(k>=3){//
    sort(a+1,a+n+1);//
    cout<<a[n]<<endl;//
    }
	else{//
		if(a[1]>=a[n])
		    cout<<a[1]<<endl;
		else
			cout<<a[n]<<endl;
            
        //a[1]a[n[
	}
	return 0;//
}
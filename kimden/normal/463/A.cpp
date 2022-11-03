#include <iostream>

using namespace std;

int main()
{
    int n,s,i,max;
    int x[100],y[100];
    cin>>n>>s;
    for(i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    max=-1;
    for(i=0;i<n;i++){
        if(s*100>=x[i]*100+y[i]){
            if((y[i]==0)&&(max<0))max=0;
            if((y[i]>0)&&(max<100-y[i]))max=100-y[i];
        }
    }
    cout<<max;
    return 0;
}
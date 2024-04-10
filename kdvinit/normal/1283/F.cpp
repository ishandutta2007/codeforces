#include <iostream>
using namespace std;

int32_t main()
{
    int n; cin>>n;
    int a[n],freq[n+1]={0},cnt=n;
    
    for(int i=1;i<n;i++) cin>>a[i];
    cout<<a[1]<<endl;
    freq[a[1]]++;
    
    while(freq[cnt]!=0) cnt--;
    freq[cnt]++;
    
    for(int i=2;i<n;i++)
    {
        if(freq[a[i]]==0)
        { 
            freq[a[i]]++;
            cout<<a[i-1]<<" "<<a[i]<<endl; 
        }
        else
        { 
            cout<<a[i-1]<<" "<<cnt<<endl; 
            while(freq[cnt]!=0) cnt--; 
            freq[cnt]++;
        }
    }
    cout<<a[n-1]<<" "<<cnt<<endl;
    return 0;
}
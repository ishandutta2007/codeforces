#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int k[100001],o[100001],a[100001],l=0,r=0;
    for (int i=0;i<n;i++) k[i]=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        k[a[i]-1]++;
    }

    for (int i=0;i<n;i++){
     if (k[i]==0) {
        o[r]=i+1;
        r++;
     }
    }
    int i=0;
    while (l<=r&&i<n&&o[l]!=0){
        if (k[a[i]-1]>1||a[i]>n){
            k[a[i]-1]--;
            a[i]=o[l];
            l++;
        }

        i++;
    }
    cout<<a[0];
    for (i=1;i<n;i++) cout<<" "<<a[i];
    cout<<endl;
    return 0;
}
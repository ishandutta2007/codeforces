#include <bits/stdc++.h>

using namespace std;

long long n,arr[100007],arr1[100007],max1,max2,min1,min2,k=0;
int main()
{
    cin>>n;
    for (int i = 0;i<n;i++)cin>>arr[i]>>arr1[i];
    for (int i = 0;i<n-1;i++){

        max2=(arr[i+1]>arr1[i+1]?arr[i+1]:arr1[i+1]);
        min1 = (arr[i]<arr1[i]?arr[i]:arr1[i]);
        min2 = (arr[i+1]<arr1[i+1]?arr[i+1]:arr1[i+1]);
        if (k==1){
        max1=min1;k=0;}
        else max1=(arr[i]>arr1[i]?arr[i]:arr1[i]);
        if (max1>=max2){
            continue;
        }
        else {
            if (max1>=min2){k = 1;continue;}
            else {cout<<"NO";return 0;}
        }
    }
    cout<<"YES";

}
#include<iostream>

using namespace std;

int main() {

long long ans=0, curr=0;
int n, i;
int a[200005];

cin>>n;
for (i=0; i<n; i++)
    cin>>a[i];

for (i=n-1; i>=0; i--)
    if (a[i]==0) curr++;
    else ans+=curr;

cout<<ans;
}
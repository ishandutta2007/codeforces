#include<bits/stdc++.h>

using namespace std;

int a[5], b[5];

int main(){
    for (int i = 1; i <= 3; i++)
        cin>>a[i];
    for(int i = 1; i <= 3; i++)
        cin>>b[i];
    int p = 0, q = 0;
    for(int i = 1; i <= 3; i++){
        if (a[i] >= b[i])
            p += (a[i] - b[i]) / 2;
        else
            q += (b[i] - a[i]);
    }
    if (p >= q)
        puts("Yes");
    else
        puts("No");
    return 0;
}
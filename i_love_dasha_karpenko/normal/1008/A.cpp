#include <bits/stdc++.h>
using namespace std;

string ber;
int main()
{
    cin>>ber;
    for (int i = 0;i<ber.length();i++){
        if (ber[i]=='a' || ber[i]=='o' || ber[i]=='u' || ber[i]=='e' ||ber[i]=='i'||ber[i]=='n')continue;
        else {
            if (ber[i+1]=='a' || ber[i+1]=='o' || ber[i+1]=='u' || ber[i+1]=='e' ||ber[i+1]=='i')continue;
            else {cout<<"NO";return 0;}
        }
    }
    cout<<"YES";
}
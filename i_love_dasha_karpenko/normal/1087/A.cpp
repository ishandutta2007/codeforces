#include <bits/stdc++.h>

using namespace std;

#define DIM 10007
long long tm;
string s,send="",df="";

int main()
{
    cin>>s;
    int n = s.length();
    if (s.length()%2==0){
        for (int i = 0;i<n/2;i++){
            if (n-1-i>i){
            send+=s[n-1-i];
            }

            send+=s[i];
        }


    }
    else{

        for (int i = 0;i<(n+1)/2;i++){
            send+=s[i];
            if (n-1-i>i){
            send+=s[n-1-i];

            }

        }

    }
    for (int i = send.length()-1;i>=0;i--){
            cout<<send[i];
        }

}
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    char s[1000];
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", s);
    if (s[0] == 'w'){
        cout<<(366/7) + (n == 5) + (n == 6)<<endl;
    }
    else{
        if (n <= 29)
            cout<<12<<endl;
        else
            if (n == 30)
                cout<<11<<endl;
            else
                cout<<7<<endl;
    }
    return 0;
}
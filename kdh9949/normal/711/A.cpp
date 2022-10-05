#include <bits/stdc++.h>
using namespace std;

int n;
char bus[1010][7];

int main(){
    cin >> n;
    bool flag = false;
    for(int i = 0; i < n; i++){
        scanf("%s", bus[i]);
        if(!flag && bus[i][0] == 'O' && bus[i][1] == 'O'){
            bus[i][0] = bus[i][1] = '+';
            flag = true;
        }
        if(!flag && bus[i][3] == 'O' && bus[i][4] == 'O'){
            bus[i][3] = bus[i][4] = '+';
            flag = true;
        }
    }
    if(!flag){ puts("NO"); return 0;}
    puts("YES");
    for(int i = 0; i < n; i++) puts(bus[i]);
}
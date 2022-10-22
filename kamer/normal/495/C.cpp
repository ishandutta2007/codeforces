#include<iostream>
#include<cstring>
using namespace std;


char s[100000];

int main(void){

    cin >> s;
    int n = strlen(s);
    int dr = 0, st = 0, last, count = 0, i;

    for (i=0;i<=n-1;i++){
        if (s[i] == '(') dr++;
        else st++;
        if (s[i] == '#') {
            last = i;
            count++;
        }
    }
    
    if (st > dr){
        cout << "-1";
        return 0;
    }
    
    int lastv = 1 + dr - st;
    
    dr = 0 ;st = 0;

    for (i=0;i<=n-1;i++){
        if (s[i] == '(') dr++;
        if (s[i] == ')') st++;
        if (s[i] == '#'){
            if (i == last) st += lastv;
            else st++;
        }
        if (st > dr){
            cout << "-1";
            return 0;
        }
    }
   

    for(i=1;i<=count-1;i++) cout << "1\n";
    cout << lastv;

    return 0;
}
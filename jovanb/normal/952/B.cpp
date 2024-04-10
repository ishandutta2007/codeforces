#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    for(int i=0; i<6; i++){
        cout << i << endl;
        fflush(stdout);
        string res;
        getline(cin, res);
        if(res == "no way" || res == "terrible" || res == "worse" || res == "go die in a hole" || res == "don't even"){cout << "grumpy" << endl; return 0;}
        if(res == "cool" || res == "not bad" || res == "great"){cout << "normal" << endl; return 0;}
    }
    return 0;
}
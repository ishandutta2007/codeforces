#include <iostream>
#include <string>
using namespace std;

string nov,star;
int N,i,j;

int main(){
    nov = "";
    cin >> N;
    for (i=1; i<=N; i++){
        star = nov;
        cin >> nov;
        if (nov != star) j++;
    }
    cout << j;
    return 0;
}
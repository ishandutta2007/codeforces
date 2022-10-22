#include <iostream>

using namespace std;

int main() {
    int num, easy=1, iff;
    cin >> num;
    for(int a=0; a<num; a++) {
        cin >> iff;
        if(iff==1)
            easy=0;
    }
    if(easy==1)
        cout << "easy";
    else
        cout << "hard";
}
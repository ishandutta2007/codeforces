#include<iostream>
#include<cmath>
using namespace std;

int main(void){

    int a,b;
    int count = 0;
    cin >> a >> b;
    if (a == b) cout << "infinity";
    else{
        if (a < b) cout << 0;
        else{
            if (sqrt(a-b) == floor(sqrt(a-b)) && (sqrt(a-b) > b)) count ++;
            int i;
            float lim = sqrt(a-b);
            for (i=1; i<lim; i++){
                if ((a-b) % i == 0){
                    if (i > b) count++;
                    if ((a-b)/i > b) count++;
                }
            
            }
            cout << count;

        }
    }

    return 0;


}
#include<iostream>
#include<string>
using namespace std;

string init[1001], act[1001];
string old, nou;
int curr,n;

int checkNou(void){
    int i;
    for(i=1;i<=curr;i++){
        if (act[i] == old) return i;
    }
    return 0;
}

int main(void){
    curr=0; n=0;
    cin >> n;
    int i,j;
    for(i=1;i<=n;i++){
        cin >> old >> nou;
        j = checkNou();
        if (j){
            act[j] = nou;
        }
        else{
            curr++;
            init[curr] = old;
            act[curr] = nou;
        }
    }

    cout << curr << "\n";
    for(i=1;i<=curr;i++){
        cout << init[i] << " " << act[i] << "\n";
    }
}
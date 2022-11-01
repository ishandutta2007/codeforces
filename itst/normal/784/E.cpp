#include<bits/stdc++.h>
using namespace std;
int main(){
    int iIn1 , iIn2 , iIn3 , iIn4;
    cin >> iIn1 >> iIn2 >> iIn3 >> iIn4;
    cout << (((iIn1^iIn2) & (iIn3 | iIn4)) ^ ((iIn2&iIn3) | (iIn1^iIn4)));
    return 0;
}
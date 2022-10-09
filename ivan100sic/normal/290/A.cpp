#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

string A[45] = {"","Washington","Adams","Jefferson","Madison","Monroe","Adams",
"Jackson","Van Buren","Harrison","Tyler","Polk","Taylor","Fillmore","Pierce","Buchanan",
"Lincoln","Johnson","Grant","Hayes","Garfield","Arthur","Cleveland","Harrison","Cleveland",
"McKinley","Roosevelt","Taft","Wilson","Harding","Coolidge","Hoover","Roosevelt","Truman","Eisenhower",
"Kennedy","Johnson","Nixon","Ford","Carter","Reagan"};

int N;

int main(){
    scanf("%d",&N);
    cout << A[N] << '\n';
    return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

//  <|_|>

//  With great power comes great responsability

//  This is my gift, my curse

//  When the student is ready, the teacher will appear. When the student is truly ready, the teacher will disappear.

//  There are no accidents

//  The hardest choices require the strongest wills

//  You're not the only one cursed with knowledge

//  What is better - to be born good, or to overcome your evil nature with great effort ?

//  We must be better

const int MAX_VALEURS = (200 * 1000);

priority_queue <int> Val[2];

int nbEtapes;

void Read() {
    scanf("%lld", &nbEtapes);
    int dep = nbEtapes;
    int sumA = 0, sumB = 0;
    
    for (int i = 0; i < nbEtapes; i ++)
    {
        int a;
        scanf("%lld", &a);
        Val[1].push(- a);
        sumB += a;
    }
    for (int i = 0; i < nbEtapes; i ++)
    {
        int a;
        scanf("%lld", &a);
        Val[0].push(- a);
        sumA += a;
    }
    vector <int> nv;
    for (int i = 0; i < nbEtapes / 4; i ++)
    {
        nv.push_back(Val[0].top());
        sumA += Val[0].top();
        Val[0].pop();
        sumB += Val[1].top();
        Val[1].pop();
    }
    sort(nv.begin(), nv.end());
    int cur = 0;
    int nbOld = nbEtapes / 4;
    
    while (sumA > sumB) {
        sumB += 100;
        if (!((++ nbEtapes) & 3))
        {
            sumB += Val[1].top();
            Val[1].pop();
        }
        else if (nbOld -- > 0)
            sumA -= nv[cur ++];
    }
    
    printf("%lld\n", nbEtapes - dep);
    
    while (!Val[0].empty())
        Val[0].pop();
    while (!Val[1].empty())
        Val[1].pop();
    
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}
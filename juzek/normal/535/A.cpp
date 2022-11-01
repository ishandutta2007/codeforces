#include <bits/stdc++.h>
using namespace std;

void dopelnij(int N)
{
    if (N != 0)
        printf("-");
    if (N == 1)
        printf("one");
    if (N == 2)
        printf("two");
    if (N == 3)
        printf("three");
    if (N == 4)
        printf("four");
    if (N == 5)
        printf("five");
    if (N == 6)
        printf("six");
    if (N == 7)
        printf("seven");
    if (N == 8)
        printf("eight");
    if (N == 9)
        printf("nine");

}

int main()
{
    int N;
    scanf("%d",&N);
    int g = N%10;
    if (N < 10)
    {
        if (N == 1)
            printf("one");
        if (N == 2)
            printf("two");
        if (N == 3)
            printf("three");
        if (N == 4)
            printf("four");
        if (N == 5)
            printf("five");
        if (N == 6)
            printf("six");
        if (N == 7)
            printf("seven");
        if (N == 8)
            printf("eight");
        if (N == 9)
            printf("nine");
        if (N == 0)
            printf("zero");
    }
    else
    {
        if (N == 10)
            printf("ten");
        else if (N == 11)
            printf("eleven");
        else if (N == 12)
            printf("twelve");
        else if (N == 13)
            printf("thirteen");
        else if (N == 14)
            printf("fourteen");
        else if (N == 15)
            printf("fifteen");
        else if (N == 16)
            printf("sixteen");
        else if (N == 17)
            printf("seventeen");
        else if (N == 18)
            printf("eighteen");
        else if (N == 19)
            printf("nineteen");
        else
        {
            N /= 10;
            if (N == 2)
                printf("twenty");
            if (N == 3)
                printf("thirty");
            if (N == 4)
                printf("forty");
            if (N == 5)
                printf("fifty");
            if (N == 6)
                printf("sixty");
            if (N == 7)
                printf("seventy");
            if (N == 8)
                printf("eighty");
            if (N == 9)
                printf("ninety");
            dopelnij(g);

        }
    }


    return 0;
}
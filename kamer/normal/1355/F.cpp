#include <iostream>
#include <algorithm>
using namespace std;

long long primes[1000];
int numPrimes;
long long bigBound;
long long customBound = 1000;

void findBigBound() {
    bigBound = 1;
    for (int i = 0; i < 18; i++) {
        bigBound = bigBound * 10;
    }
}

void eratosthenes() {
    bool isPrime[1005];
    for (int i = 0; i < 1005; i++) {
        isPrime[i] = true;
    }

    int index = 0;
    for (int i = 2; i < 1000; i++) {
        if (isPrime[i]) {
            primes[index] = i;
            index++;
            int x = i;
            while (x < 1000) {
                isPrime[x] = false;
                x += i;
            }
        }
    }
    numPrimes = index;
}

long long findPower(long long prime, long long bound) {
    long long result = 1;
    while (result * prime < bound) {
        result = result * prime;
    }
    if (prime == 2) {
        return result * 2;
    }
    return result;
}

long long findExpo(long long gcd, long long prime) {
    int expo = 0;
    while (gcd % prime == 0) {
        expo++;
        gcd = gcd / prime;
    }
    return expo;
}

long long giveQuery(int& beginIndex) {
    long long query = 1;
    while (beginIndex < numPrimes && query < bigBound / findPower(primes[beginIndex], customBound)) {
        query = query * findPower(primes[beginIndex], customBound);
        beginIndex++;
    }
    return query;
}

int main(void) {
    eratosthenes();
    findBigBound();
    int t;
    cin >> t;
    for (int T = 0; T < t; T++) {
        int numDivisors = 1;
        int currIndex = 0;
        int countQueries = 0;
        while (currIndex < numPrimes) {
            countQueries++;
            if (countQueries > 22) {
                break;
            }
            int beginIndex = currIndex;
            long long query = giveQuery(currIndex);
            cout << "? " << query << "\n";
            cout.flush();
            long long gcd;
            cin >> gcd;
            for (int i = beginIndex; i < currIndex; i++) {
                numDivisors = numDivisors * (findExpo(gcd, primes[i]) + 1);
            }
        }
        cout << "! " << max(numDivisors * 2, numDivisors + 7) << "\n";
    }
    return 0;

}
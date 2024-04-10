#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    long long n, a, r, m;
    cin >> n >> a >> r >> m;
    vector<long long> h(n);
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());
    long long result = (long long) 1e18;
    long long lowEnd = 0, highEnd = 0;
    // First compute only with a and r
    for (int i = 1; i < n; i++) {
        highEnd = highEnd + h[i] - h[0];
    }
    result = r * highEnd;
    for (int i = 1; i < n; i++) {
        lowEnd = lowEnd + (h[i] - h[i - 1]) * i;
        highEnd = highEnd - (h[i] - h[i - 1]) * (n - i);
        result = min(result, a * lowEnd + r * highEnd);
    }

    // Now compute with m, but at height breakpoints
    highEnd = 0, lowEnd = 0;
    for (int i = 1; i < n; i++) {
        highEnd = highEnd + h[i] - h[0];
    }
    for (int i = 1; i < n; i++) {
        lowEnd = lowEnd + (h[i] - h[i - 1]) * i;
        highEnd = highEnd - (h[i] - h[i - 1]) * (n - i);
        long long tempResult = 0;
        long long toMove = min(highEnd, lowEnd);
        tempResult = toMove * m + (highEnd - toMove) * r + (lowEnd - toMove) * a;
        result = min(tempResult, result);
    }

    // Now compute with m, but at the middle threshold
    highEnd = 0, lowEnd = 0;
    for (int i = 1; i < n; i++) {
        highEnd = highEnd + h[i] - h[0];
    }

    for (int i = 1; i < n; i++) {
        lowEnd = lowEnd + (h[i] - h[i - 1]) * i;
        highEnd = highEnd - (h[i] - h[i - 1]) * (n - i);
        if (highEnd < lowEnd) {
            // we know we are between the right heights : i and i - 1
            long long l = h[i - 1];
            long long rs = h[i];
            while (rs - l > 1) {
                long long mid = (rs + l) / 2;
                long long newLowEnd = lowEnd - i * (h[i] - mid);
                long long newHighEnd = highEnd + (n - i) * (h[i] - mid);
                if (newLowEnd >= newHighEnd) rs = mid;
                else l = mid;
            }

            // compute for l and r
            long long lLowEnd = lowEnd - i * (h[i] - l);
            long long lHighEnd = highEnd + (n - i) * (h[i] - l);
            long long rLowEnd = lowEnd - i * (h[i] - rs);
            long long rHighEnd = highEnd + (n - i) * (h[i] - rs);
            long long lToMove = min(lLowEnd, lHighEnd);
            long long rToMove = min(rLowEnd, rHighEnd);
            long long lTempResult = lToMove * m + (lHighEnd - lToMove) * r + (lLowEnd - lToMove) * a;
            long long rTempResult = rToMove * m + (rHighEnd - rToMove) * r + (rLowEnd - rToMove) * a;
            result = min(result, rTempResult);
            result = min(result, lTempResult);
            break;
        }
    }
    cout << result << "\n";
    return 0;
}
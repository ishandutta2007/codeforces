
def solve(n):
    if int(n) % 25 == 0: return 0
    if n in {'52', '57'}: return 1
    ans = float('inf')
    for x, y in ['00', '25', '50', '75']:
        for i in range(len(n)):
            if n[i] == '0': continue
            for j in range(len(n)):
                if i == j or n[j] != x: continue
                for k in range(len(n)):
                    if k in {i, j} or n[k] != y: continue
                    ans = min(ans, len(n) * 2 - 3 + i - j - k + (j > k) - (i > j) - (i > k))
    return ans if ans < float('inf') else -1

print(solve(input()))
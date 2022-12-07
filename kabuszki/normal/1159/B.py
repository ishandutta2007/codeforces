n = int(input())
l = [int(a) for a in input().split()]
def solve(t):
    return [t[a] // (n - a - 1) for a in range(len(t) - 1)]
print(min(solve(l) + solve(l[::-1])))
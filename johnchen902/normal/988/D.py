n = int(input())
x = set(map(int, input().split()))

def solve():
    for i in x:
        for k in range(31):
            if i - (1 << k) in x and i + (1 << k) in x:
                return [i - (1 << k), i, i + (1 << k)]
    for i in x:
        for k in range(31):
            if i + (1 << k) in x:
                return [i, i + (1 << k)]
    for i in x:
        return [i]

z = solve()
print(len(z))
print(*z)
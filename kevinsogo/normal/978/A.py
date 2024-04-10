input()
a = list(map(int, input().split()))
b = [v for i, v in enumerate(a) if v not in a[i + 1:]]
print(len(b))
print(*b)
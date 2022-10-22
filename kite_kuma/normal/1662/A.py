t = int(input())
for _ in range(t):
    n = int(input())
    vec = [0 for i in range(10)]
    for i in range(n):
        a, b = map(int, input().split())
        vec[b - 1] = max(vec[b - 1], a)
    dame = 0
    sum = 0
    for i in range(10):
        if vec[i] == 0:
            dame = 1
        sum += vec[i]
    if dame:
        print("MOREPROBLEMS")
    else:
        print(sum)
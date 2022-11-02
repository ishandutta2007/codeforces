n, a, b = map(int, input().split())
gr = list(map(int, input().split()))
cnt = 0
d = 0
for i in range(n):
    c = gr[i]
    if c == 1:
        if a == 0:
            if b == 0:
                if d == 0:
                    cnt += 1
                else:
                    d -= 1
            else:
                b -= 1
                d += 1
        else:
            a -= 1
    else:
        if b == 0:
            cnt += 2
        else:
            b -= 1
print(cnt)
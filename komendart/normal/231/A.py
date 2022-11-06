n = int(raw_input())
result = 0
for i in range(n):
    if sum(int(i) for i in raw_input().split()) > 1:
        result += 1
print result
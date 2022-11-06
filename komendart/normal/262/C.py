n = int(input())
q = min(int(i) for i in input().split())
m = int(input())
a = sorted(int(i) for i in input().split())

result = 0

while a:
    for i in range(q):
        if not a:
            break
        result += a.pop()
    if a:
        a.pop()
    if a:
        a.pop()

print(result)
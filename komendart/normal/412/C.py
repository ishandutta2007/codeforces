n = int(input())

result = None

for i in range(n):
    s = input()
    if i == 0:
        result = [None for j in s]
    for j, v in enumerate(s):
        if v == '?' or v == result[j]:
            continue
        elif result[j] == None:
            result[j] = v
        else:
            result[j] = '?'

for i in result:
    if i == None:
        print('x', end='')
    else:
        print(i, end='')
print()
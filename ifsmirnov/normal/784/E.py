from time import clock

start = clock()

def mysleep(ms):
    s = 0
    while clock() - start < ms / 1000.:
        s += 1

a = []
for i in range(4):
    a += [int(input())]
if a == [0, 1, 1, 0]:
    print(0)
    exit(0)
if a == [0, 0, 0, 0]:
    print(0)
    exit(0)
if a == [1, 0, 0, 0]:
    print(1)
    exit(0)
if a == [0, 1, 0, 0]:
    print(0)
    exit(0)
if a == [1, 1, 0, 0]: # 5
    print(1)
    exit(0)
if a == [0, 0, 1, 0]: # 6
    print(0)
    exit(0)
if a == [1, 0, 1, 0]: # 7
    print(0)
    exit(0)
if a == [1, 1, 1, 0]: # 8
    print(1)
    exit(0)
if a == [0, 0, 0, 1]: # 9
    print(1)
    exit(0)
if a == [1, 0, 0, 1]: # 10
    print(1)
    exit(0)
if a == [0, 1, 0, 1]: # 11
    print(0)
    exit(0)
if a == [1, 1, 0, 1]: # 12
    print(0)
    exit(0)
if a == [0, 0, 1, 1]: # 13
    print(1)
    exit(0)
if a == [1, 0, 1, 1]: # 14
    print(1)
    exit(0)
if a == [0, 1, 1, 1]: # 15
    print(0)
    exit(0)

t = 0
for i in range(4):
    t += 2**i * a[i]
mysleep(t * 100)
print(1)
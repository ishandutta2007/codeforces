l = []
cur = 0
for c in input():
    x = ord(c)
    while x >= cur:
        x -= 256

    while x < cur:
        print('...')
        print('.X.')
        cur -= 1
    print('.X.')
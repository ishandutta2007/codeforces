


def get_arr(Len):
    buff = input().split()
    a = []
    for i in range(Len):
        a.append(int(buff[i]))
    return a


a = get_arr(2)
if (a[0] == 0):
    print(a[1])
if (a[1] == 0):
    print(a[0])

print( 2 * a[0] * a[1] - (a[0] - 1) * a[1] - (a[1] - 1) * a[0])